import json
import os

URL = "https://leetcode.com/problems/"
LANG_LIST = [{'name': 'C++', 'slug': 'cpp', 'id': 0, 'extension': '.cpp'}, {'name': 'Java', 'slug': 'java', 'id': 1, 'extension': '.java'}, {'name': 'Python', 'slug': 'python', 'id': 2, 'extension': '.py'}, {'name': 'MySQL', 'slug': 'mysql', 'id': 3, 'extension': '.sql'}, {'name': 'C', 'slug': 'c', 'id': 4, 'extension': '.c'}, {'name': 'C#', 'slug': 'csharp', 'id': 5, 'extension': '.cs'}, {'name': 'JavaScript', 'slug': 'javascript', 'id': 6, 'extension': '.js'}, {'name': 'Ruby', 'slug': 'ruby', 'id': 7, 'extension': '.rb'}, {'name': 'Bash', 'slug': 'bash', 'id': 8, 'extension': '.sh'}, {'name': 'Swift', 'slug': 'swift', 'id': 9, 'extension': '.swift'}, {'name': 'Go', 'slug': 'golang', 'id': 10, 'extension': '.go'}, {'name': 'Python3', 'slug': 'python3', 'id': 11, 'extension': '.py'}, {'name': 'Scala', 'slug': 'scala', 'id': 12, 'extension': '.scala'}, {'name': 'Kotlin', 'slug': 'kotlin', 'id': 13, 'extension': '.kt'}, {'name': 'MS SQL Server', 'slug': 'mssql',
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     'id': 14, 'extension': '.sql'}, {'name': 'Oracle', 'slug': 'oraclesql', 'id': 15, 'extension': '.sql'}, {'name': 'HTML', 'slug': 'html', 'id': 16, 'extension': '.html'}, {'name': 'Python ML (beta)', 'slug': 'pythonml', 'id': 17, 'extension': '.py'}, {'name': 'Rust', 'slug': 'rust', 'id': 18, 'extension': '.rs'}, {'name': 'PHP', 'slug': 'php', 'id': 19, 'extension': '.php'}, {'name': 'TypeScript', 'slug': 'typescript', 'id': 20, 'extension': '.ts'}, {'name': 'Racket', 'slug': 'racket', 'id': 21, 'extension': '.rkt'}, {'name': 'Erlang', 'slug': 'erlang', 'id': 22, 'extension': '.erl'}, {'name': 'Elixir', 'slug': 'elixir', 'id': 23, 'extension': '.ex'}, {'name': 'Dart', 'slug': 'dart', 'id': 24, 'extension': '.dart'}, {'name': 'Python Data Science (beta)', 'slug': 'pythondata', 'id': 25, 'extension': '.py'}, {'name': 'React', 'slug': 'react', 'id': 26, 'extension': '.js'}, {'name': 'Vanilla JS', 'slug': 'vanillajs', 'id': 27, 'extension': '.js'}]
table = {}

excluded_directories = ["tools", ".git"]
excluded_files = [".gitignore", ".gitattributes", "README.md"]
dir_path = os.path.dirname(os.path.dirname(os.path.realpath(__file__)))

for root, dirs, files in os.walk(dir_path):
    dirs[:] = [d for d in dirs if d not in excluded_directories]
    files[:] = [f for f in files if f not in excluded_files]
    for file in files:
        file_name = os.path.splitext(file)[0]
        file_ext = os.path.splitext(file)[1]

        shown_file_name = file_name.split(".")[-1][1:]
        slug = shown_file_name.replace(" ", "-").lower()

        file_name_path = file_name.replace(" ", "%20")

        if file_ext == ".md":
            continue

        for lang in LANG_LIST:
            if lang["extension"] == file_ext:
                file_lang = lang["name"]
                break

        task_number = file_name.split(".")[0]
        if task_number not in table:
            table[task_number] = {}
            table[task_number]["Title"] = f"[{shown_file_name}]({URL}{slug}/)"
            table[task_number]["Solution"] = []
            table[task_number]["Difficulty"] = root.split("\\")[-1]

        path_to_folder = root.split("\\")[-1]

        solution = f"[{file_lang}]({path_to_folder}/{file_name_path}{file_ext})"
        if solution not in table[task_number]["Solution"]:
            table[task_number]["Solution"].append(solution)

        md_file = f"{root}/{file_name}.md"
        if os.path.isfile(md_file):
            if "Description" not in table[task_number]:
                table[task_number]["Description"] = f"[Description]({path_to_folder}/{file_name_path}.md)"

table = dict(sorted(table.items(), key=lambda item: int(item[0])))

with open("README.md", "r") as f:
    lines = f.readlines()

index = lines.index("# List of solved problems\n")
lines = lines[:index + 1]

lines.append("| # | Title | Solution | Difficulty | Description |\n")
lines.append("|---| ----- | -------- | ---------- | ----------- |\n")

for key, value in table.items():
    solutions = ", ".join(value["Solution"])
    lines.append(
        f"| {key} | {value['Title']} | {solutions} | {value['Difficulty']} | {value['Description']} |\n")

with open("README.md", "w") as f:
    f.writelines(lines)

print('done')
