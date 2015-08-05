# This file is generated by gyp; do not edit.

TOOLSET := target
TARGET := init
DEFS_Debug := \
	'-DNODE_GYP_MODULE_NAME=init' \
	'-D_LARGEFILE_SOURCE' \
	'-D_FILE_OFFSET_BITS=64' \
	'-DBUILDING_NODE_EXTENSION' \
	'-DDEBUG' \
	'-D_DEBUG'

# Flags passed to all source files.
CFLAGS_Debug := \
	-fPIC \
	-pthread \
	-Wall \
	-Wextra \
	-Wno-unused-parameter \
	-m64 \
	-g \
	-O0

# Flags passed to only C files.
CFLAGS_C_Debug :=

# Flags passed to only C++ files.
CFLAGS_CC_Debug := \
	-fno-rtti \
	-fno-exceptions

INCS_Debug := \
	-I/home/amine/.node-gyp/0.12.4/src \
	-I/home/amine/.node-gyp/0.12.4/deps/uv/include \
	-I/home/amine/.node-gyp/0.12.4/deps/v8/include \
	-I/usr/include/cairo \
	-I/usr/include/glib-2.0 \
	-I/usr/lib/x86_64-linux-gnu/glib-2.0/include \
	-I/usr/include/pixman-1 \
	-I/usr/include/freetype2 \
	-I/usr/include/libpng12

DEFS_Release := \
	'-DNODE_GYP_MODULE_NAME=init' \
	'-D_LARGEFILE_SOURCE' \
	'-D_FILE_OFFSET_BITS=64' \
	'-DBUILDING_NODE_EXTENSION'

# Flags passed to all source files.
CFLAGS_Release := \
	-fPIC \
	-pthread \
	-Wall \
	-Wextra \
	-Wno-unused-parameter \
	-m64 \
	-O3 \
	-ffunction-sections \
	-fdata-sections \
	-fno-tree-vrp \
	-fno-tree-sink \
	-fno-omit-frame-pointer

# Flags passed to only C files.
CFLAGS_C_Release :=

# Flags passed to only C++ files.
CFLAGS_CC_Release := \
	-fno-rtti \
	-fno-exceptions

INCS_Release := \
	-I/home/amine/.node-gyp/0.12.4/src \
	-I/home/amine/.node-gyp/0.12.4/deps/uv/include \
	-I/home/amine/.node-gyp/0.12.4/deps/v8/include \
	-I/usr/include/cairo \
	-I/usr/include/glib-2.0 \
	-I/usr/lib/x86_64-linux-gnu/glib-2.0/include \
	-I/usr/include/pixman-1 \
	-I/usr/include/freetype2 \
	-I/usr/include/libpng12

OBJS := \
	$(obj).target/$(TARGET)/src/init.o \
	$(obj).target/$(TARGET)/src/color.o \
	$(obj).target/$(TARGET)/src/qr_image.o \
	$(obj).target/$(TARGET)/src/qr_cairo.o

# Add to the list of files we specially track dependencies for.
all_deps += $(OBJS)

# CFLAGS et al overrides must be target-local.
# See "Target-specific Variable Values" in the GNU Make manual.
$(OBJS): TOOLSET := $(TOOLSET)
$(OBJS): GYP_CFLAGS := $(DEFS_$(BUILDTYPE)) $(INCS_$(BUILDTYPE))  $(CFLAGS_$(BUILDTYPE)) $(CFLAGS_C_$(BUILDTYPE))
$(OBJS): GYP_CXXFLAGS := $(DEFS_$(BUILDTYPE)) $(INCS_$(BUILDTYPE))  $(CFLAGS_$(BUILDTYPE)) $(CFLAGS_CC_$(BUILDTYPE))

# Suffix rules, putting all outputs into $(obj).

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(srcdir)/%.cc FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

# Try building from generated source, too.

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj).$(TOOLSET)/%.cc FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj)/%.cc FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

# End of this set of suffix rules
### Rules for final target.
LDFLAGS_Debug := \
	-pthread \
	-rdynamic \
	-m64

LDFLAGS_Release := \
	-pthread \
	-rdynamic \
	-m64

LIBS := \
	-lcairo \
	-lqrencode

$(obj).target/init.node: GYP_LDFLAGS := $(LDFLAGS_$(BUILDTYPE))
$(obj).target/init.node: LIBS := $(LIBS)
$(obj).target/init.node: TOOLSET := $(TOOLSET)
$(obj).target/init.node: $(OBJS) FORCE_DO_CMD
	$(call do_cmd,solink_module)

all_deps += $(obj).target/init.node
# Add target alias
.PHONY: init
init: $(builddir)/init.node

# Copy this to the executable output path.
$(builddir)/init.node: TOOLSET := $(TOOLSET)
$(builddir)/init.node: $(obj).target/init.node FORCE_DO_CMD
	$(call do_cmd,copy)

all_deps += $(builddir)/init.node
# Short alias for building this executable.
.PHONY: init.node
init.node: $(obj).target/init.node $(builddir)/init.node

# Add executable to "all" target.
.PHONY: all
all: $(builddir)/init.node
