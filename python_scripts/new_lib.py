# This script creates in same folder a couple of files: lib_name.c and lib_name.h
# with a description of the library
lib_name = input("Enter new library name:\r\n").lower()
description = input("Enter new library description:\r\n").capitalize()
author = "butaforsky"
version = "0.1.0"


with open(lib_name+".c", 'w') as f:
    # add 5 strings in it
    f.write("/**")
    f.write("\n")
    f.write(" * \n")
    # add brief comment in C header
    f.write(" * ")
    f.write("@brief " + description)
    f.write("\n");
    f.write(" * @author " + author + "\n")
    f.write(" * @version " + version + "\n")
    f.write(" */\n")
    f.write("\n")
    f.write("#include \"" + lib_name + ".h\"\n")
    f.write("#include \"short_types.h\"\n\n")
    # add C comment for user defines, enums, functions, structs and functions
    f.write("/* User defines */\n\n")
    f.write("/* User enums */\n\n")
    f.write("/* User structs */\n\n")
    f.write("/* User typedefs */\n\n")
    f.write("/* User variables */\n\n")
    f.write("/* User functions */\n\n")
    f.write("\n")

    for i in range(5):
        f.write("\n")


with open(lib_name+".h", 'w') as file:
    # add 5 strings in it
    # add comment in C header
    # add doxigen comment in C header
    file.write("#ifndef __" + lib_name.upper() + "_H__\n")
    file.write("#define __" + lib_name.upper() + "_H__\n")
    file.write("\n")
    file.write("/**\n")
    file.write(" * \n")
    # add brief comment in C header
    file.write(" * ")
    file.write("@brief " +description)
    file.write(" * \n")
    file.write(" * @author " + author + "\n")
    file.write(" * @version " + version + "\n")
    file.write(" */\n")
    file.write("\n")
    file.write("#include \"main.h\"\n")
    file.write("#include \"short_types.h\"\n\n")
    # add C comment for user defines, enums, functions, structs and functions
    file.write("/* User defines */\n\n")
    file.write("/* User enums */\n\n")
    file.write("/* User structs */\n\n")
    file.write("/* User typedefs */\n\n")
    file.write("/* User variables */\n\n")
    file.write("/* User functions */\n\n")
    file.write("\n")

    for i in range(5):
        file.write("\n")
    file.write("#endif\n")
