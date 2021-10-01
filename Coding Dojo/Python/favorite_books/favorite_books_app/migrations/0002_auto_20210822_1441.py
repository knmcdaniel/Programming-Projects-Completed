# Generated by Django 2.2 on 2021-08-22 19:41

from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    dependencies = [
        ('favorite_books_app', '0001_initial'),
    ]

    operations = [
        migrations.CreateModel(
            name='Favorites',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
            ],
        ),
        migrations.AlterField(
            model_name='books',
            name='users_that_favorited',
            field=models.ManyToManyField(through='favorite_books_app.Favorites', to='favorite_books_app.User'),
        ),
        migrations.AddField(
            model_name='favorites',
            name='book',
            field=models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, related_name='book_favorited', to='favorite_books_app.Books'),
        ),
        migrations.AddField(
            model_name='favorites',
            name='user',
            field=models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, related_name='user_favorited', to='favorite_books_app.User'),
        ),
    ]