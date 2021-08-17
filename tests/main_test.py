from py_rename_exchange.main import main


def test_main_empty(capsys):
    main(['']) == 1


def test_arg_amount(capsys):
    main(['a', 'b', 'c']) == 1
