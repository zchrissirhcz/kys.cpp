import sledpkg as sp
import os

class CodeWriter(object):
    def __init__(self, indent_len):
        self.lines = []
        self.indent_num = 0
        self.indent_len = indent_len

    def write(self, content):
        padding = (self.indent_len * self.indent_num) * ' '
        line = padding + content
        self.lines.append(line)

    def show(self):
        for line in self.lines:
            print(line)

    def save(self, savepath):
        with open(savepath, "w") as fout:
            for line in self.lines:
                fout.write(line + "\n")

    def tab(self):
        self.indent_num += 1

    def backspace(self):
        if (self.indent_num > 0):
            self.indent_num -= 1


def prepare_mlcc():
    pkg = sp.SledPackage('mlcc')
    pkg.clone_repo('https://github.com/scarsty/mlcc', commit_id='64c25fb')

    src_dir = "deps/mlcc"
    src_lst = []
    for item in os.listdir(src_dir):
        ext = item.split('.')[-1]
        if ext in ["h", "cpp"]:
            src_lst.append(item)
    
    writer = CodeWriter(2)
    writer.write("add_library(mlcc INTERFACE")
    writer.tab()
    for item in src_lst:
        writer.write(item)
    writer.backspace()
    writer.write(")")

    writer.write("target_include_directories(mlcc INTERFACE")
    writer.tab()
    writer.write('${CMAKE_CURRENT_SOURCE_DIR}')
    writer.backspace()
    writer.write(")")

    savepath = f"{src_dir}/CMakeLists.txt"
    writer.save(savepath)
    print(f"Writing to {savepath}, Use it with:")
    print("   add_subdirectory(mlcc)")
    print("   target_link_libraries(your_target PUBLIC mlcc)")

if __name__ == '__main__':
    prepare_mlcc()