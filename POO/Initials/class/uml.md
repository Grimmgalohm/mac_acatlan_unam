# UML.md

- Diagramas de clase
Son los diagramas que se hacen para representar visualmente las relaciones de las clases de un programa
- Diagramas de casos de uso
Son los diagramas que bajan a un nivel menos tecnico el
- Diagrama de procesos/actividades
Se ingresan todo lo que hace el codigo a distintos niveles

```
# Clase base
class Notification:
    def send(self):
        raise NotImplementedError("This method should be overridden.")

# Clase derivada para notificaciones por correo electrónico
class EmailNotification(Notification):
    def __init__(self, email_address):
        self.email_address = email_address

    def send(self):
        print(f"Sending email to {self.email_address}")

# Clase derivada para notificaciones por SMS
class SMSNotification(Notification):
    def __init__(self, phone_number):
        self.phone_number = phone_number

    def send(self):
        print(f"Sending SMS to {self.phone_number}")

# Clase derivada para notificaciones push
class PushNotification(Notification):
    def __init__(self, device_id):
        self.device_id = device_id

    def send(self):
        print(f"Sending push notification to device {self.device_id}")

# Uso del sistema
notifications = [
    EmailNotification(&quot;alice@example.com"),
    SMSNotification("123-456-7890"),
    PushNotification("device_001"),
]

for notification in notifications:
    notification.send()
```
