#pragma once

#include <memory>
#include "Core.h"

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

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
#define SK_CORE_TRACE(...) ::Skull::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SK_CORE_INFO(...)  ::Skull::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SK_CORE_WARN(...)  ::Skull::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SK_CORE_ERROR(...) ::Skull::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SK_CORE_FATAL(...) ::Skull::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//client log macros
#define SK_TRACE(...) ::Skull::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SK_INFO(...)  ::Skull::Log::GetClientLogger()->info(__VA_ARGS__)
#define SK_WARN(...)  ::Skull::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SK_ERROR(...) ::Skull::Log::GetClientLogger()->error(__VA_ARGS__)
#define SK_FATAL(...) ::Skull::Log::GetClientLogger()->fatal(__VA_ARGS__)
