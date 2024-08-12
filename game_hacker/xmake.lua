target("csgo_hacker")
do
    set_kind("binary")
    add_files("src/*.cpp")
    set_pcxxheader("include/pch.h")

    add_headerfiles("include/*.h")
    add_includedirs("include")

    add_deps("hackerlib")
    add_includedirs("$(projectdir)")
end