import os

from py_rename_exchange.main import _py_rename_exchange
from py_rename_exchange.main import main


def test_main_empty(capsys):
    main(['']) == 1


def test_arg_amount(capsys):
    main(['a', 'b', 'c']) == 1


def test_directory_replace(tmpdir):
    a = tmpdir.mkdir('sub1')
    a.join('file1.txt').write('file1')
    b = tmpdir.mkdir('sub2')
    b.join('file2.txt').write('file2')

    _py_rename_exchange(str(a), str(b))

    assert os.path.isfile(f'{tmpdir}/sub1/file2.txt')
    assert os.path.isfile(f'{tmpdir}/sub2/file1.txt')

# def test_missing_directory(tmpdir, capsys):
#     a = tmpdir.mkdir('sub1')
#     a.join('file1.txt').write('file1')
#     b = ''
#
#     out, err = capsys.readouterr()
