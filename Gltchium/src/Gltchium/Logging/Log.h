#pragma once

#include "Gltchium/Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Gltchium {
	class GLTCHIUM_API Log {
		public:
			static void Init();

			inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
			inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
		private:
			static std::shared_ptr<spdlog::logger> s_CoreLogger;
			static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define GC_CORE_TRACE(...)    ::Gltchium::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GC_CORE_INFO(...)     ::Gltchium::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GC_CORE_WARN(...)     ::Gltchium::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GC_CORE_ERROR(...)    ::Gltchium::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GC_CORE_FATAL(...)    ::Gltchium::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define GC_TRACE(...)	      ::Gltchium::Log::GetClientLogger()->trace(__VA_ARGS__)
#define GC_INFO(...)	      ::Gltchium::Log::GetClientLogger()->info(__VA_ARGS__)
#define GC_WARN(...)	      ::Gltchium::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GC_ERROR(...)	      ::Gltchium::Log::GetClientLogger()->error(__VA_ARGS__)
#define GC_FATAL(...)	      ::Gltchium::Log::GetClientLogger()->fatal(__VA_ARGS__)