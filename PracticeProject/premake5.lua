project "PracticeProject"
    kind "Makefile"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir("../bin/" .. outputdir .. "/%{prj.name}")
    objdir("../build/" .. outputdir .. "/%{prj.name}")

    files {
        "src/**.cpp",
        "include/**.h"
    }

    includedirs {
        "include"
    }

    defines {
        "WINDOWS"
    }

    filter { "configurations:Debug" }
        buildoptions "/MTd"
        runtime "Debug"
        symbols "on"

    filter { "configurations:Release" }
        buildoptions "/MT"
        runtime "Release"
        optimize "on"

    buildcommands {
        "make %{cfg.buildcfg}"
    }

    rebuildcommands {
        "make %{cfg.buildcfg} rebuild"
    }

    cleancommands {
        "make clean %{cfg.buildcfg}"
    }