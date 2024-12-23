workspace "LifeSim"
    architecture "x64"

    configurations {
        "Debug",
        "Release",
    }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    project "LifeSim"
        location "LifeSim"
        kind "ConsoleApp"
        language "C++"

        targetdir ("bin/" .. outputdir .. "/%{prj.name}")
        objdir("bin-int/" .. outputdir .. "/%{prj.name}")

        files {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp"
        }

        includedirs {
            "%{prj.name}/src",
            "%{prj.name}/vendor/Scribble2D/include"
        }

        libdirs {
            "%{prj.name}/vendor/Scribble2D/lib/Debug",
            "%{prj.name}/vendor/Scribble2D/lib/Release"
        }

        filter "system:windows"
            cppdialect "C++17"
            staticruntime "On"
            systemversion "latest"

        filter "configurations:Debug"
            links { "Scribble2D-Core_Debug.lib" }
            symbols "On"

        filter "configurations:Release"
            links { "Scribble2D-Core_Release.lib" }
            optimize "On"

        filter "action:vs*"
            buildoptions { "/utf-8" }
