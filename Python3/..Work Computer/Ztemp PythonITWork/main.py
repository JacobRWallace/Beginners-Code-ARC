import pandas as pd
from gui import UI
from datetime import date

def cleanup(data):
    #data = pd.read_csv("qualifying-examination-report-2023-09-25.csv")
    data['Student RNumber'] = data['Student RNumber'].astype(str)
    data['Student RNumber'] = data['Student RNumber'].str.zfill(8)
    data['Student RNumber'] = 'R' + data['Student RNumber'].astype(str)
    data['Full Name'] = data['Student Name (First)'] + " " + data['Student Name (Last)']
    data['Full Name'].str.capitalize()
    data['Chair Full Name'] = "Dr. " + data['Committee Chair (First Name)'].str.capitalize() + " " + data['Committee Chair (Last Name)'].str.capitalize()
    data['Committee Co-Chair (First Name)'] = data['Committee Co-Chair (First Name)'].astype(str)
    data['Committee Co-Chair (Last Name)'] = data['Committee Co-Chair (Last Name)'].astype(str)
    
    data['CoChair Full Name'] = "Dr. " + data['Committee Co-Chair (First Name)'].str.capitalize() + " " + data['Committee Co-Chair (Last Name)'].str.capitalize()
    data['Program'] = data['Program'].apply(lambda st: st[st.find("(")+1:st.find(")")])
    newdata = data[['Student RNumber', 'Full Name', 'Student Name (Last)','Student Email', 'Date of Exam', 'Student Expected Graduation Term'
                    ,'Program','Student successfully completed qualifying exam', 'Chair Full Name',
                    'Chair of Committee Email Address','Does student have co-chair?','CoChair Full Name',
                    'Co-Chair of Committee Email Address','Submission Date', 'Final Status']]
    newdata['CoChair Full Name'] = newdata['CoChair Full Name'].replace('Dr. Nan Nan', '')
    
    
    majors = pd.read_csv("Z:\private\GradEnrollment\Ali's Projects\Majors_Database.csv")
    
    merged_db = pd.merge(newdata, majors, left_on = 'Program', right_on = 'Code', how = 'left')
    merged_db = merged_db[['Student RNumber', 'Student Name (Last)','Full Name','Major','Student Email', 'Date of Exam', 'Student Expected Graduation Term'
                    ,'Degree','Major','Student successfully completed qualifying exam', 'Chair Full Name',
                    'Chair of Committee Email Address','Does student have co-chair?','CoChair Full Name',
                    'Co-Chair of Committee Email Address','Submission Date', 'Final Status']]
    return merged_db
    
def main():
    user = UI()
    user.setup()
    data = cleanup(user.df)
    todays_date = str(date.today())
    data.to_excel("Quals_Clean_up_"+todays_date+".xlsx", index = False)
    
main()