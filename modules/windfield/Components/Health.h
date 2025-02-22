#ifndef HEALTH_COMPONENT_H
#define HEALTH_COMPONENT_H
#include "core/object/object.h"
#include "core/object/ref_counted.h"

class Health : public Object {
	GDCLASS(Health, Object)

	int max_health;
	int current_health;
protected:
	static void _bind_methods();
public:
	Health(int starting_health);
	Health(int starting_health, int max_health);
	Health(const Health &other);
	Health(Health &&other) noexcept;
	Health& operator=(Health&& other) noexcept;

	int get_current_health() const;
	bool is_dead() const;
	int damage(int health_to_remove);
	int heal(int health_to_add);
};

#endif
