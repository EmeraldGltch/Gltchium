workspace "Gltchium"
	architecture "x64"
	startproject "Sandbox"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Gltchium/vendor/GLFW/include"
IncludeDir["Glad"] = "Gltchium/vendor/Glad/include"
IncludeDir["ImGui"] = "Gltchium/vendor/imgui"

group "Dependencies"
	include "Gltchium/vendor/GLFW"
	include "Gltchium/vendor/Glad"
	include "Gltchium/vendor/imgui"
group ""

project "Gltchium"
	location "Gltchium"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "gcpch.h"
	pchsource "Gltchium/src/gcpch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
	}

	links {
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "10.0.17134.0"

		defines {
			"GC_PLATFORM_WINDOWS",
			"GC_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "GC_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "GC_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "GC_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"Gltchium/vendor/spdlog/include",
		"Gltchium/src"
	}

	links {
		"Gltchium"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "10.0.17134.0"

		defines {
			"GC_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "GC_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "GC_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "GC_DIST"
		runtime "Release"
		optimize "On"
