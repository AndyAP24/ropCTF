#This will be a dockerfile for a ROP capture the flag challenge.

FROM ubuntu:latest AS build 
    RUN apt-get update && apt-get install -y build-essential 
    RUN mkdir /app 
    WORKDIR /app 
    COPY . /app 


    #Install gcc
    RUN apt-get install -y gcc

    #Compile rop.c
    RUN gcc -o rop rop.c -fno-stack-protector -no-pie -z execstack

    #Clean up
    RUN rm -rf /var/lib/apt/lists/*
    RUN apt-get clean
    
FROM ubuntu:latest as rop

    RUN apt-get update && apt-get install -y build-essential

    #Install gdb
    RUN apt-get install -y gdb

    #Copy files from build
    COPY --from=build /app/rop /app/rop
    COPY --from=build /app/hex2raw /app/hex2raw




    #Make a user with credentials labuser:labuser
    RUN useradd -m labuser
    RUN echo "labuser:labuser" | chpasswd

    #Allow labuser to create files in /app
    RUN chown labuser:labuser /app


    USER labuser

    #Restric the user to this directory
    WORKDIR /app

    



