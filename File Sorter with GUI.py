import os
import shutil
import tkinter as tk
from tkinter import ttk, filedialog, messagebox
import ttkbootstrap as ttk

def create_dir(path):
    if not os.path.exists(path):
        os.makedirs(path)

def move_file(file_path, target_dir):
    create_dir(target_dir)
    shutil.move(file_path, target_dir)

def sort(directory):
    for item in os.listdir(directory):
        item_path = os.path.join(directory, item)
        if os.path.isfile(item_path):
            file_ext = item.split('.')[-1]
            target_dir = os.path.join(directory, file_ext.upper() + '_files')
            move_file(item_path, target_dir)

def select_folder():
    folder_path = filedialog.askdirectory()
    if folder_path:
        folder_entry.delete(0, tk.END)
        folder_entry.insert(0, folder_path)

def start_sorting():
    folder_path = folder_entry.get()
    if folder_path and os.path.isdir(folder_path):
        sort(folder_path)
        messagebox.showinfo("Success", f"Files in {folder_path} have been sorted based upon file extension.")
    else:
        messagebox.showwarning("Invalid Folder", "Please select a valid folder to sort.")

mainframe = ttk.Window(themename = 'journal')
mainframe.title("File Sorter")
mainframe.geometry("400x200")
mainframe.resizable(False, False)

folder_path_label = ttk.Label(mainframe, text="Select Folder:")
folder_path_label.pack(pady=10)

folder_entry = ttk.Entry(mainframe, width=50)
folder_entry.pack(pady=5)

select_button = ttk.Button(mainframe, text="Browse", command=select_folder)
select_button.pack(pady=5)

sort_button = ttk.Button(mainframe, text="Sort Files", command=start_sorting)
sort_button.pack(pady=20)

mainframe.mainloop()