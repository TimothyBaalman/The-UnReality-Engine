#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace UnReality {

	class UR_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_clientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_coreLogger;
		static std::shared_ptr<spdlog::logger> s_clientLogger;
	};
}
// TODO Wrap every define in an if a dist to set to an empty define
// Core Log Macros
#define UR_CORE_TRACE(...)  ::UnReality::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define UR_CORE_INFO(...)   ::UnReality::Log::GetCoreLogger()->info(__VA_ARGS__)
#define UR_CORE_WARN(...)   ::UnReality::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define UR_CORE_ERROR(...)  ::UnReality::Log::GetCoreLogger()->error(__VA_ARGS__)
#define UR_CORE_CRIT(...)   ::UnReality::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client Log Macros
#define UR_TRACE(...)       ::UnReality::Log::GetClientLogger()->trace(__VA_ARGS__)
#define UR_INFO(...)        ::UnReality::Log::GetClientLogger()->info(__VA_ARGS__)
#define UR_WARN(...)        ::UnReality::Log::GetClientLogger()->warn(__VA_ARGS__)
#define UR_ERROR(...)       ::UnReality::Log::GetClientLogger()->error(__VA_ARGS__)
#define UR_CRIT(...)        ::UnReality::Log::GetClientLogger()->critical(__VA_ARGS__)