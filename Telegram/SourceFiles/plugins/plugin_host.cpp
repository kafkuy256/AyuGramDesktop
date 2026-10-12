/*
This file is part of Telegram Desktop,
the official desktop application for the Telegram messaging service.

For license and copyright information please follow this link:
https://github.com/telegramdesktop/tdesktop/blob/master/LEGAL
*/
#include "plugins/plugin_host.h"

#include <cstdio>

#if defined(PLUGIN_HOST_WITH_PYTHON)
#include <Python.h>
#endif

namespace Plugins {

bool Start() {
#if defined(PLUGIN_HOST_WITH_PYTHON)
	// WHY: 0 leaves signal handlers to Qt; Python installing its own makes
	// an ordinary quit fault on the Qt thread.
	if (!Py_InitializeEx(0)) {
		std::fputs("PLUGIN HOST: Py_InitializeEx failed\n", stderr);
		return false;
	}
	PyRun_SimpleString(
		"import sys\n"
		"sys.stderr.write('PLUGIN HOST: python %d.%d.%d ready\\n'"
		"    % sys.version_info[:3])\n"
		"sys.stderr.flush()\n");
	std::fputs("PLUGIN HOST: started\n", stderr);
	return true;
#else
	std::fputs(
		"PLUGIN HOST: python not linked, PLUGIN_HOST_WITH_PYTHON undefined\n",
		stderr);
	return false;
#endif
}

} // namespace Plugins