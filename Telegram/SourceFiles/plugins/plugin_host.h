/*
This file is part of Telegram Desktop,
the official desktop application for the Telegram messaging service.

For license and copyright information please follow this link:
https://github.com/telegramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

namespace Plugins {

// WHY: the probe reports through stderr so a CI run answers the question
// without needing a plugin, a settings page, or any user interaction.
[[nodiscard]] bool Start();

} // namespace Plugins