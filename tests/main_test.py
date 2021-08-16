from py_rename_exchange.main import main


def test_main(capsys):
    main()
    out, err = capsys.readouterr()
    assert out == 'hello world\n'
    assert err == ''
