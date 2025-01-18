#pragma once


#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Scribble {

	class Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

#ifdef CORE_DEBUG
#define SCB_CORE_ERROR(...) ::Scribble::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SCB_CORE_TRACE(...) ::Scribble::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SCB_CORE_INFO(...)  ::Scribble::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SCB_CORE_WARN(...)  ::Scribble::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SCB_CORE_FATAL(...) ::Scribble::Log::GetCoreLogger()->critical(__VA_ARGS__)

#else
#define SCB_CORE_ERROR(...)
#define SCB_CORE_TRACE(...)
#define SCB_CORE_INFO(...)
#define SCB_CORE_WARN(...)
#define SCB_CORE_FATAL(...)
#endif

#define SCB_ERROR(...) ::Scribble::Log::GetClientLogger()->error(__VA_ARGS__)
#define SCB_TRACE(...) ::Scribble::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SCB_INFO(...)  ::Scribble::Log::GetClientLogger()->info(__VA_ARGS__)
#define SCB_WARN(...)  ::Scribble::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SCB_FATAL(...) ::Scribble::Log::GetClientLogger()->critical(__VA_ARGS__)