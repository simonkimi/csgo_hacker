target("hacklib")
do
    set_kind("static")
    add_files("src/*.cpp")
    add_headerfiles("include/*.h")
    add_includedirs("include")
    set_pcxxheader("include/pch.h")
end 