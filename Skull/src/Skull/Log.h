#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Skull {
	class SKULL_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger;  }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//core log macros
#define SK_CORE_TRACE(...) ::Skull::Log::GetCoreLogger()->trace(_VA_ARGS_)
#define SK_CORE_INFO(...)  ::Skull::Log::GetCoreLogger()->info(_VA_ARGS_)
#define SK_CORE_WARN(...)  ::Skull::Log::GetCoreLogger()->warn(_VA_ARGS_)
#define SK_CORE_ERROR(...) ::Skull::Log::GetCoreLogger()->error(_VA_ARGS_)
#define SK_CORE_FATAL(...) ::Skull::Log::GetCoreLogger()->fatal(_VA_ARGS_)

//client log macros
#define SK_TRACE(...) ::Skull::Log::GetClientLogger()->trace(_VA_ARGS_)
#define SK_INFO(...)  ::Skull::Log::GetClientLogger()->info(_VA_ARGS_)
#define SK_WARN(...)  ::Skull::Log::GetClientLogger()->warn(_VA_ARGS_)
#define SK_ERROR(...) ::Skull::Log::GetClientLogger()->error(_VA_ARGS_)
#define SK_FATAL(...) ::Skull::Log::GetClientLogger()->fatal(_VA_ARGS_)
