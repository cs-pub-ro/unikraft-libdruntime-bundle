UK_ROOT ?= $(PWD)/../../unikraft
UK_LIBS ?= $(PWD)/../../libs

LIBS := $(UK_LIBS)/lib-compiler-rt:$(UK_LIBS)/lib-libcxx:$(UK_LIBS)/lib-libcxxabi:$(UK_LIBS)/lib-libucontext:$(UK_LIBS)/lib-libunwind:$(UK_LIBS)/lib-gcc:$(UK_LIBS)/lib-pthread-embedded:$(UK_LIBS)/newlib:$(UK_LIBS)/lwip:$(UK_LIBS)/druntime

all:
	@$(MAKE) -C $(UK_ROOT) A=$(PWD) L=$(LIBS)

$(MAKECMDGOALS):
	@$(MAKE) -C $(UK_ROOT) A=$(PWD) L=$(LIBS) $(MAKECMDGOALS)
