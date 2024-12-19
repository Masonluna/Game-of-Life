workspace "LifeSim"
    architecture "x64"

    configurations {
        "Debug",
        "Release",
    }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    include "LifeSim/vendor/Scribble2D/Scribble2D-Core"

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
            "%{prj.name}/vendor/Scribble2D/Scribble2D-Core",
            "%{prj.name}/vendor/Scribble2D/Scribble2D-Core/src",
            "%{prj.name}/vendor/Scribble2D/Scribble2D-Core/vendor/spdlog/include",
            "%{prj.name}/vendor/Scribble2D/Scribble2D-Core/vendor/GLFW/include",
            "%{prj.name}/vendor/Scribble2D/Scribble2D-Core/vendor/Glad/include",
            "%{prj.name}/vendor/Scribble2D/Scribble2D-Core/vendor/glm/glm-1.0.1"
        }

        libdirs {
            "%{prj.name}/vendor/Scribble2D/Scribble2D-Core/vendor/spdlog/lib",
            "%{prj.name}/vendor/Scribble2D/Scribble2D-Core/vendor/GLFW/lib",
            "%{prj.name}/vendor/Scribble2D/Scribble2D-Core/vendor/Glad/build/Debug"

        }


        links {
            "Scribble2D-Core",
            "glfw3_mt.lib",
            "Glad",
            "opengl32.lib",
            "spdlog.lib"
        }

        filter "system:windows"
            cppdialect "C++17"
            staticruntime "On"
            systemversion "latest"

        filter "configurations:Debug"
            symbols "On"

        filter "configurations:Release"
            optimize "On"

        filter "action:vs*"
            buildoptions { "/utf-8" }
