import os

from py_rename_exchange.main import main
# from py_rename_exchange.main import _py_rename_exchange


def test_main_empty(capsys):
    main(['']) == 1


def test_arg_amount(capsys):
    main(['a', 'b', 'c']) == 1


def test_directory_replace(tmpdir):
    a = tmpdir.mkdir('sub1').join('file1.txt')
    a.write('file1')
    b = tmpdir.mkdir('sub2').join('file2.txt')
    b.write('file2')

    print(a)
    print(b)

    # _py_rename_exchange(str(a), str(b))

    assert os.path.isfile(f'{tmpdir}/sub1/file1.txt')
    assert os.path.isfile(f'{tmpdir}/sub2/file2.txt')
