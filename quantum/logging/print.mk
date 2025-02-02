PRINTF_PATH = $(LIB_PATH)/printf/src

VPATH += $(PRINTF_PATH) $(PRINTF_PATH)/printf
#SRC += printf.c
QUANTUM_SRC +=$(QUANTUM_DIR)/logging/print.c

OPT_DEFS += -DPRINTF_SUPPORT_DECIMAL_SPECIFIERS=0
OPT_DEFS += -DPRINTF_SUPPORT_EXPONENTIAL_SPECIFIERS=0
OPT_DEFS += -DPRINTF_SUPPORT_LONG_LONG=0
OPT_DEFS += -DPRINTF_SUPPORT_WRITEBACK_SPECIFIER=0
OPT_DEFS += -DSUPPORT_MSVC_STYLE_INTEGER_SPECIFIERS=0
OPT_DEFS += -DPRINTF_ALIAS_STANDARD_FUNCTION_NAMES=1
