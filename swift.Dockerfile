FROM amd64/swift:latest

WORKDIR /local_workflow

COPY ./ ./

RUN swift package resolve
RUN swift package update
RUN swift package show-dependencies

ENTRYPOINT ["/bin/linux/local_workflow"]