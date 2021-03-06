PROJECT_NAME := bitluni

EXTRA_COMPONENT_DIRS := \
	$(abspath .) \
	$(abspath unit_tester) \
	$(IDF_PATH)/tools/unit-test-app/components/

CFLAGS += \
		-Werror

include $(IDF_PATH)/make/project.mk

.PHONY: tests

tests:
	$(MAKE) \
		TEST_COMPONENTS='src' \
		flash monitor;

tests-enc:
	$(MAKE) \
		TEST_COMPONENTS='src' \
		encrypted-flash monitor;

