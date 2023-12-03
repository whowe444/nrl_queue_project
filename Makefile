# src: https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/

SUBDIRS = src test

all: $(SUBDIRS)
$(SUBDIRS):
	$(MAKE) -C $@

.PHONY: all $(SUBDIRS)
