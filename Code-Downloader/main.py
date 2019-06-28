# Author : Sahil Rajput
# Github : GitHub/sahil-rajput

import requests
from bs4 import BeautifulSoup
import time
import sys
import os
if(len(sys.argv)==1):
	print "URL :"
	url=raw_input();
	if("http://" not in url):
		url="http://"+url
elif(len(sys.argv)>2):
	print "\n----ONE URL ONLY----\n"
	exit()
else:
	url=sys.argv[1];
	if("http://" not in url):
		url="http://"+sys.argv[1]
try:
	response = requests.get(url,timeout=2.0)

except:
	print "\n----TIME OUT----\n"
	exit()
if(response.status_code!=requests.codes.ok):
	print "\n----INVALID URL----\n"
	exit()
else:
	print "\n----Wait----\n"
	soup = BeautifulSoup(response.text,"lxml") 
	soup.encode("ascii")
	titl=soup.title.text
	txt = soup.find_all('pre')
	lst=[];
	count=0;
	for code in txt:
		lst.append(code.text)
		count+=1
	x=min(count,3)
	if(x==0):
		print "\n----NO CODE FOUND----\n"
		exit()
	else:
		fil_name=[]
		i=0
		directory="/Users/sahil/Desktop/geeksforgeeks_codes/"
		if not os.path.exists(directory):
			os.makedirs(directory)
		for code in lst:
			if(i>=x):
				break
			fil_name.append(directory+"%d.cpp"%(i+1))
			fd=open(fil_name[i],'w')
			fd.write(code)
			fd.close()
			print "\nProgram = %d Obtained."%(i+1);
			time.sleep(0.19)
			i+=1
