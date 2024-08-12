target("hacklib")
do
    set_kind("static")
    add_files("include/*.ixx")
    set_pcxxheader("include/pch.h")
end 