# py-rename-exchange

This is a solution for a puzzle created by @asottile, this is just for fun and a learning experience for C
extensions in Python.

The usage is for atomic directory replacement using RENAME_EXCHANGE.

---

# install

To install this tool download/clone this repo first, then:

```console
$ pip install .
```

# usage

`py-rename-exchange-cli path1 path2`

# build

Included is script to build `manylinux` wheels using Podman:

```console
$ python bin/build-abi-wheels
```

# testing

Also included is a testsuite using tox:

```console
$ virtualenv venv && . ./venv/bin/activate
$ pip install -r requirements-dev.txt && pip install .
$ tox
```
