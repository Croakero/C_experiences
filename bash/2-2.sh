#! /bin/bash

macro()
{
	echo $(pwd) > "pwd.bin"
}

polo()	
{
	cd $(cat "pwd.bin")
}
