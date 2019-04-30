Example of c++ project, which is built and launched inside docker container.

Goals:
- min steps to build from sources
- min steps to deploy dev env
- min prerequisites (to not polute host environment with dozens of tools/dependencies)

---

Build & run in docker
---

Prerequisites: (1) [docker](https://www.docker.com/), (2) git, (3) unix shell (e.g. bash).

```
git clone https://github.com/artin-phares/cpp-docker-example
cd cpp-docker-example

./scripts/build.sh          # build inside docker container
./scripts/build-and-run.sh  # build inside docker container and run it
```

Notes:  
On linux, if docker requires `sudo` - setup it to run without `sudo` ([instructions](https://askubuntu.com/a/477554/950607)).

Run prebuild docker
---

Prerequisites: (1) [docker](https://www.docker.com/).

```
# download image from docker hub and run it (set port and folder path to save database in)
docker run -di \
    -p <port>:8080 \
    --mount type=bind,src=<database folder path>,dst=/opt/project/build/bin/data/ \
    artinphares/cpp-docker-example
```

Notes:  
Database folder path should be (1) absolute, (2) exist, (3) windows format: "/d/my/folder/".
