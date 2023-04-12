workspace "Gltchium"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Gltchium"
	location "Gltchium"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h}",
		"%{prj.name}/src/**.cpp}",
	}

	includedirs {
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"GC_PLATFORM_WINDOWS",
			"GC_BUILD_DLL",
			"_WINDLL"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "GC_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "GC_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "GC_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"

	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h}",
		"%{prj.name}/src/**.cpp}",
	}

	includedirs {
		"%{prj.name}/vendor/spdlog/include",
		"Gltchium/src"
	}

	links {
		"Gltchium"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"GC_PLATFORM_WINDOWS",
			"_WINDLL"
		}

	filter "configurations:Debug"
		defines "GC_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "GC_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "GC_DIST"
		optimize "On"