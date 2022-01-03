workspace "Workspace"
    architecture "x64"

    configurations {
        "Debug",
        "Release"
    }

    startproject "PracticeProject"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "PracticeProject"

newaction {
    trigger = "clean",
    description = "Remove all binaries and intermediate binaries, and vs files.",
    execute = function()
        print("Removing binaries")
        os.rmdir("./bin")
        print("Removing intermediate binaries")
        os.rmdir("./bin-int")
        print("Done")
    end
}