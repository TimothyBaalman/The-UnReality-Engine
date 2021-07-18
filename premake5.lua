workspace "The-UnReality-Engine"
    architecture "x64"

    configurations {
        "Debug",
        "Release",
        "Dist"
    }

    startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "The-UnReality-Engine"
    location "The-UnReality-Engine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-interm/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.0.17763.0"

        defines {
            "UR_PLATFORM_WINDOWS",
            "UR_BUILD_DLL"
        }

        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "UR_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "UR_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "UR_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-interm/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "The-UnReality-Engine/vendor/spdlog/include",
        "The-UnReality-Engine/src"
    }

    links {
        "The-UnReality-Engine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.0.17763.0"

        defines {
            "UR_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "UR_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "UR_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "UR_DIST"
        optimize "On"