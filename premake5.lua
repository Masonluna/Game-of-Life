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
            "Scribble2D/Scribble2D-Core/include"
        }

        libdirs {
            "Scribble2D/bin/Debug-windows-x86_64/Scribble2D-Core",
            "Scribble2D/bin/Release-windows-x86_64/Scribble2D-Core"
        }

        dependson { "Scribble2D-Core" }

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


        include "Scribble2D/Scribble2D-Core"
