target("csgo_hacker")
do
    set_kind("binary")
    add_files("src/*.cpp", "src/*.ixx")
    set_pcxxheader("include/Pch.h")

    add_deps("hacklib")
    add_includedirs("$(projectdir)/hacklib/include")
end