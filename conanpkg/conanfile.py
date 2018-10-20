from conans import ConanFile, CMake, tools


class ReadlineConan(ConanFile):
    name = "readline"
    version = "0.1"
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False]}
    default_options = "shared=True"
    generators = "cmake"

    def source(self):
        self.run("git clone git://git.savannah.gnu.org/readline.git")
        self.run("cd readline && git checkout readline-8.0-beta")

    def build(self):
        self.run("cd " + self.source_folder)
        self.run("./readline/configure --srcdir=readline")
        self.run("make -j")

    def package(self):
        #self.copy("*.h", dst="include", src="hello")
        #self.copy("*hello.lib", dst="lib", keep_path=False)
        self.copy("*.so.*", dst="lib", src="shlib")
        self.copy("*.h", dst="include")

    def package_info(self):
        self.cpp_info.libs = ["readline"]

