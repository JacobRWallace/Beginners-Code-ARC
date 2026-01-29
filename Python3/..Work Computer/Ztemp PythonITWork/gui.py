from tkinter import *
from tkinter.ttk import Combobox
from pathlib import Path
from tkinter import filedialog
import shutil
import os
import pandas as pd


class UI():
    def __init__(self):
        self.window=Tk()
        self.df = None
        self.upload_button = Button(self.window, text="Upload File" ,command=self.upload_file_Audit)
        self.code = ''

    def setup(self):
        self.window.geometry("500x500+50+50")
        self.window.title("Qual Exam GUI")
        lbl=Label(self.window, text="Hi there, welcome to Ali's Qual Exam Cleaner.", fg='purple', font=("Times New Roman", 12))
        lbl.place(x=100, y=25)
        #combobox label
        #combo box        
        #upload
        uplabel = Label(self.window, text = "Please upload the most recent copy of the qual exam file.", fg='purple', font=("Times New Roman", 10))
        uplabel.place(x=100, y=80)
        self.upload_button.place(x=400, y=80)
        
        
        # Button for closing
        exit_button = Button(self.window, text="Submit Choices", command=self.Close)
        exit_button.place(x=150, y=300)
        self.window.mainloop()

        
    def upload_file_Audit(self):
        file_path = filedialog.askopenfilename()
        if file_path:
            file_name = os.path.basename(file_path)
            cwd = os.getcwd()
            destination_path = os.path.join(cwd, file_name)
            shutil.copy(file_path, destination_path)
            conlabel = Label(self.window, text = "File: "+file_name+" Uploaded", fg='purple', font=("Times New Roman", 10))
            conlabel.place(x=100, y=100)
            self.df = pd.read_csv(destination_path) 

            
    def Close(self):
        self.window.destroy()
    