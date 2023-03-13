workspace "GameEngine_ai22m003"
	architecture "x64"
	startproject "Ehms_Game"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "GEE/vendor/GLFW/include"

include "GEE/vendor/GLFW"

project "GEE"
	location "GEE"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "geepch.h"
	pchsource "GEE/src/geepch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs 
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"GEE_PLATFORM_WINDOWS",
			"GEE_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Ehms_Game")
		}

	filter "configurations:Debug"
		defines "GEE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "GEE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "GEE_DIST"
		optimize "On"

project "Ehms_Game"
	location "Ehms_Game"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs 
	{
		"GEE/vendor/spdlog/include",
		"GEE/src"
	}

	links
	{
		"GEE"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"GEE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "GEE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "GEE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "GEE_DIST"
		optimize "On"