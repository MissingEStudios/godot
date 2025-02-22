#include "Health.h"
#include "thirdparty/jolt_physics/Jolt/Math/Math.h"

void Health::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_current_health"), &Health::get_current_health);
	ClassDB::bind_method(D_METHOD("is_dead"), &Health::is_dead);
	ClassDB::bind_method(D_METHOD("damage", "health_to_remove"), &Health::damage);
	ClassDB::bind_method(D_METHOD("heal", "health_to_add"), &Health::heal);
}

Health::Health(int starting_health) : max_health(starting_health), current_health(starting_health) {
}

Health::Health(int starting_health, int max_health) : max_health(max_health), current_health(starting_health) {
}

Health::Health(const Health &other) {
	max_health = other.max_health;
	current_health = other.current_health;
}

Health::Health(Health &&other) noexcept {
	max_health = other.max_health;
	current_health = other.current_health;
}

Health & Health::operator=(Health &&other) noexcept {
	if (this != &other) {
		max_health = other.max_health;
		current_health = other.current_health;
	}
	return *this;
}

int Health::get_current_health() const {
	return current_health;
}

bool Health::is_dead() const {
	return current_health <= 0;
}

int Health::damage(int health_to_remove) {
	current_health = Clamp(current_health - health_to_remove, 0, max_health);
	return current_health;
}

int Health::heal(int health_to_add) {
	current_health = Clamp(current_health + health_to_add, 0, max_health);
	return current_health;
}
