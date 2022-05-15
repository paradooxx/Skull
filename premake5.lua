workspace "Skull"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Skull"
	location "Skull"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" ..outputdir .. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SK_PLATFORM_WINDOWS",
			"SK_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath}  ../bin/"  ..outputdir.. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "SK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SK_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "SK_DIST"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" ..outputdir .. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Skull/vendor/spdlog/include",
		"Skull/src"  
	}

	links
	{
		"Skull"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SK_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "SK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SK_RELEASE"
		optimize  "On"
		
	filter "configurations:Dist"
		defines "SK_DIST"
		optimize "On"