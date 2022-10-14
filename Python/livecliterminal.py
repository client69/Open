#use_yum-install-httpd for downlaod apache server
#yum start httpd for running the apache server
#! /usr/bin/python3
import cgi
import subprocess
import json
print("content-type: text/html")
print()

user_input = cgi.FIeldStorage()
command = user_input.getvalue("x")
output= subprocess.getstatusoutput("{0}".format(command))
StatusCode = output[0]
result = output[1]
db = {"Result" : result, "statusCode" : StatusCode}
finalResult = json.dumps(db)
print(finalResult)
