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

project "GameEngine_ai22m003"
	location "GameEngine_ai22m003"
	kind "SharedLib"
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
		"%{prj.name}/vendor/spdlog/include"
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
		"GameEngine_ai22m003/vendor/spdlog/include",
		"GameEngine_ai22m003/src"
	}

	links
	{
		"GameEngine_ai22m003"
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