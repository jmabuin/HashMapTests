include ./Makefile.common

.PHONY: libhashmultimap.so clean

all: libhashmultimap.so
	@echo "================================================================================"
	@echo "Native libraries have been built."
	@echo "Location    = $(LOCATION)/"
	@echo "JAVA_HOME   = $(JAVA_HOME)"
	@echo "================================================================================"

hashmultimap:
	if [ ! -d "$(BUILD_DIR_HASHMULTIMAP)" ]; then mkdir $(BUILD_DIR_HASHMULTIMAP); fi
	$(CC) $(HASHMULTIMAP_FLAGS) hashmultimapnative.cpp -o $(BUILD_DIR_HASHMULTIMAP)/hashmultimapnative.o $(LIBMHASHMULTIMAP_LIBS)

libhashmultimap.so: hashmultimap
	$(CC) $(LIBHASHMULTIMAP_FLAGS) $(BUILD_DIR_HASHMULTIMAP)/libhashmultimap.so $(BUILD_DIR_HASHMULTIMAP)/*.o $(LIBMHASHMULTIMAP_LIBS)
	cp $(BUILD_DIR_HASHMULTIMAP)/libhashmultimap.so ../../../target/classes/

clean:
	$(RMR) $(BUILD_DIR_HASHMULTIMAP)

