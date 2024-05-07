FROM amd64/swift:latest

WORKDIR /local_workflow

COPY ./ ./

RUN swift package -v show-dependencies

ENTRYPOINT ["/bin/linux/local_workflow"]