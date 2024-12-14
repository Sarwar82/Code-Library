{
	"cmd" : ["g++ -std=c++17 $file_name -o $file_base_name && timeout 4s ./$file_base_name<input.txt>output.txt"],
	"selector" : "source.c,source.cpp,source.c++",
	"file_regex": "^(..[^:]*):([0-9]+):?([0-9]+)?:? (.*)$",
	"shell":true,
	"working_dir" : "$file_path"
}
