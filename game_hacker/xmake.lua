target("csgo_hacker")
do
    set_kind("binary")
    add_files("src/*.cpp")
    add_headerfiles("src/*.h")
    add_deps("win32_utils")
    add_includedirs("$(projectdir)/win32_utils/include")
end