#include "register_classes.h"

#include "Components/Health.h"
#include "core/object/class_db.h"


void initialize_windfield_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
	ClassDB::register_class<Health>();
}

void unintialize_windfield_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}
