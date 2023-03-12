#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace GEE {
	class GEE_API Log
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

//core log macros
#define GEE_CORE_TRACE(...) ::GEE::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GEE_CORE_INFO(...) ::GEE::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GEE_CORE_WARN(...) ::GEE::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GEE_CORE_ERROR(...) ::GEE::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GEE_CORE_FATAL(...) ::GEE::Log::GetCoreLogger()->critical(__VA_ARGS__)

//client log macros
#define GEE_TRACE(...) ::GEE::Log::GetClientLogger()->trace(__VA_ARGS__)
#define GEE_INFO(...) ::GEE::Log::GetClientLogger()->info(__VA_ARGS__)
#define GEE_WARN(...) ::GEE::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GEE_ERROR(...) ::GEE::Log::GetClientLogger()->error(__VA_ARGS__)
#define GEE_FATAL(...) ::GEE::Log::GetClientLogger()->critical(__VA_ARGS__)