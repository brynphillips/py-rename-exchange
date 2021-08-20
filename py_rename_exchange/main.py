import argparse
from typing import Optional
from typing import Sequence

from _rename_exchange import rename_exchange


def _py_rename_exchange(path1: str, path2: str) -> int:
    try:
        print(rename_exchange(path1, path2))
        return 1
    except OSError as exc:
        raise RuntimeError('failed to find directory') from exc
        return 0


def main(argv: Optional[Sequence[str]] = None) -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument('paths', help='filenames', nargs='+', type=str)
    args = parser.parse_args(argv)

    if args.paths == '':
        print('Must pass paths!')
        return 1

    if len(args.paths) > 2:
        print('Sorry too many arguments, max is 2.')
        return 1

    ret = 0
    # print(args.paths)
    if len(args.paths) == 2:
        try:
            _py_rename_exchange(args.paths[0], args.paths[1])
            ret = 1
        except ValueError:
            print('Something went wrong')
            ret = 0

    return ret


if __name__ == '__main__':
    SystemExit(main())
