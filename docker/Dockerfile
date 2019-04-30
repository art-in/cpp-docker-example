FROM project-example-tools

COPY . /opt/project/

# generate build system and build the project
WORKDIR /opt/project/build
RUN cmake -S . -B ./build-system
RUN cmake --build ./build-system --config Release

CMD ["/opt/project/build/bin/project-example"]