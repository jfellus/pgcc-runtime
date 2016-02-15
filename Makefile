all: install


install: scripts/*
	@mkdir -p ~/.pgcc/
	@cp -f scripts/* ~/.pgcc/
	@~/.pgcc/pgcc-include-path pgcc ./src


uninstall:
	@~/.pgcc/pgcc-include-path -d pgcc
